#include "Scrollbar.h"

using namespace Applications::Services::GUI;

void Scrollbar::render(std::shared_ptr<TFT_eSPI> tft)
{
    // int barWidth = 2;
    // int barHeight = TFT_HEIGHT;
    // int barX = TFT_WIDTH - barWidth;
    // int barY = 0;
    // int currentPage = 0;
    // int itemsPerPage = 3;

    // int scrollPosition = 30;
    // // Desenha a barra de rolagem na lateral direita
    // tft->fillRect(barX, barY, barWidth, barHeight, TFT_DARKGREY);

    // // Calcula a posição da "cabeça" da barra de rolagem
    // int scrollBarHeight = barY + (barHeight - scrollBarHeight) * currentPage / (this->_totalItems / itemsPerPage);
    // int scrollBarY = map(scrollPosition, 0, TFT_WIDTH - barHeight, 0, TFT_WIDTH - barHeight);

    // // Desenha a "cabeça" da barra de rolagem
    // tft->fillRect(barX, scrollBarY, barWidth, scrollBarHeight, TFT_GREEN);
}

void Scrollbar::setCurrentItem(int currentItem)
{
    this->_currentItem = currentItem;
}

void Scrollbar::setTotalItems(int totalItems)
{
    this->_totalItems = totalItems;
}
