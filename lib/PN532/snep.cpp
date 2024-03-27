
#include "snep.h"
#include "PN532_debug.h"

int8_t SNEP::write(const uint8_t *buf, uint8_t len, uint16_t timeout)
{
	if (0 >= llcp.activate(timeout))
	{
		DMSG("failed to activate PN532 as a target\n");
		return -1;
	}

	if (0 >= llcp.connect(timeout))
	{
		DMSG("failed to set up a connection\n");
		return -2;
	}

	// response a success SNEP message
	headerBuf[0] = SNEP_DEFAULT_VERSION;
	headerBuf[1] = SNEP_REQUEST_PUT;
	headerBuf[2] = 0;
	headerBuf[3] = 0;
	headerBuf[4] = 0;
	headerBuf[5] = len;
	if (0 >= llcp.write(headerBuf, 6, buf, len))
	{
		return -3;
	}

	uint8_t rbuf[16];
	if (6 > llcp.read(rbuf, sizeof(rbuf)))
	{
		return -4;
	}

	// check SNEP version
	if (SNEP_DEFAULT_VERSION != rbuf[0])
	{
		DMSG("The received SNEP message's major version is different\n");
		// To-do: send Unsupported Version response
		return -4;
	}

	// expect a put request
	if (SNEP_RESPONSE_SUCCESS != rbuf[1])
	{
		DMSG("Expect a success response\n");
		return -4;
	}

	llcp.disconnect(timeout);

	return 1;
}

int16_t SNEP::read(uint8_t *buf, uint8_t len, uint16_t timeout)
{
	if (0 >= llcp.activate(timeout))
	{
		DMSG("failed to activate PN532 as a target\n");
		return -1;
	}

	if (0 >= llcp.waitForConnection(timeout))
	{
		DMSG("failed to set up a connection\n");
		return -2;
	}

	uint16_t status = llcp.read(buf, len);
	if (6 > status)
	{
		return -3;
	}

	// check SNEP version

	// in case of platform specific bug, shift SNEP message for 4 bytes.
	// tested on Nexus 5, Android 5.1
	if (SNEP_DEFAULT_VERSION != buf[0] && SNEP_DEFAULT_VERSION == buf[4])
	{
		for (uint8_t i = 0; i < len - 4; i++)
		{
			buf[i] = buf[i + 4];
		}
	}

	if (SNEP_DEFAULT_VERSION != buf[0])
	{
		DMSG(F("SNEP->read: The received SNEP message's major version is different, me: "));
		DMSG(SNEP_DEFAULT_VERSION);
		DMSG(", their: ");
		DMSG(buf[0]);
		DMSG("\n");
		// To-do: send Unsupported Version response
		return -4;
	}

	// expect a put request
	if (SNEP_REQUEST_PUT != buf[1])
	{
		DMSG("Expect a put request\n");
		return -4;
	}

	// check message's length
	uint32_t length = (buf[2] << 24) + (buf[3] << 16) + (buf[4] << 8) + buf[5];
	// length should not be more than 244 (header + body < 255, header = 6 + 3 + 2)
	if (length > (status - 6))
	{
		DMSG("The SNEP message is too large: ");
		DMSG_INT(length);
		DMSG_INT(status - 6);
		DMSG("\n");
		return -4;
	}
	for (uint8_t i = 0; i < length; i++)
	{
		buf[i] = buf[i + 6];
	}

	// response a success SNEP message
	headerBuf[0] = SNEP_DEFAULT_VERSION;
	headerBuf[1] = SNEP_RESPONSE_SUCCESS;
	headerBuf[2] = 0;
	headerBuf[3] = 0;
	headerBuf[4] = 0;
	headerBuf[5] = 0;
	llcp.write(headerBuf, 6);

	return length;
}
