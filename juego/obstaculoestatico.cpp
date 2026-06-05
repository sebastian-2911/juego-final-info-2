#include "obstaculoestatico.h"

ObstaculoEstatico::ObstaculoEstatico(float x, float yReal, TipoEstatico tipo)
    : Obstaculo(x, yReal),
    tipoEstatico(tipo)
{
    switch (tipoEstatico)
    {
    case OBS_PIEDRA:
        sprite.load(":/piedra.png");
        break;
    case OBS_CADAVER:
        sprite.load(":/cadaver.png");
        break;
    }
}

void ObstaculoEstatico::renderizar(QPainter& painter)
{
    renderizar(painter, 0.0f);
}

void ObstaculoEstatico::renderizar(QPainter& painter, float scrollMundo)
{
    if (!estaActiva()) return;

    int screenX = static_cast<int>(getXReal());
    int screenY = static_cast<int>(getYReal() + scrollMundo);

    if (!sprite.isNull())
        painter.drawPixmap(screenX, screenY, RENDER_W, RENDER_H, sprite);
    else
    {
        // Fallback: cubo de color según tipo, para errores
        painter.setBrush(tipoEstatico == OBS_PIEDRA
                             ? QColor(120, 120, 120)   // gris = piedra
                             : QColor(80,  40,  20));  // marrón = cadáver
        painter.setPen(Qt::NoPen);
        painter.drawRect(screenX, screenY, RENDER_W, RENDER_H);
    }
}