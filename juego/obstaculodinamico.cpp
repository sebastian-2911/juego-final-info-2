#include "obstaculodinamico.h"
#include <QTransform>
#include <cstdlib>

ObstaculoDinamico::ObstaculoDinamico(float x,
                                     float yReal,
                                     TipoDinamico tipo,
                                     int carril)
    : Obstaculo(x, yReal),
    tipoDinamico(tipo),
    frameActual(0),
    contadorAnimacion(0),
    mirarDerecha(true)
{
    QPixmap hoja;

    switch (tipoDinamico)
    {
    case OBS_SOLDADO:

        hoja.load(":/soldado.png");

        sprites[0] = hoja.copy(0,    0, 512, 1024);
        sprites[1] = hoja.copy(512,  0, 512, 1024);
        sprites[2] = hoja.copy(1024, 0, 512, 1024);

        break;

    case OBS_RHAEGAR:

        hoja.load(":/rhaegar1.png");

        sprites[0] = hoja;
        sprites[1] = hoja;
        sprites[2] = hoja;

        break;
    }
    switch(carril)
    {
    case 0:
        mirarDerecha = true;
        break;

    case 1:
        mirarDerecha = rand() % 2;
        break;

    case 2:
        mirarDerecha = false;
        break;
    }
}
void ObstaculoDinamico::actualizar()
{
    contadorAnimacion++;

    if (contadorAnimacion >= 8)
    {
        contadorAnimacion = 0;
        frameActual = (frameActual + 1) % 3;
    }
}
void ObstaculoDinamico::renderizar(QPainter& painter)
{
    renderizar(painter, 0.0f);
}

void ObstaculoDinamico::renderizar(QPainter& painter,
                                   float scrollMundo)
{
    if (!estaActiva()) return;

    int screenX = static_cast<int>(getXReal());
    int screenY = static_cast<int>(getYReal() + scrollMundo);

    QPixmap spriteActual = sprites[frameActual];

    if(!mirarDerecha)
    {
        spriteActual =
            spriteActual.transformed(
                QTransform().scale(-1,1));
    }

    painter.drawPixmap(
        screenX - RENDER_W/2 + 25,
        screenY - RENDER_H + 80,
        RENDER_W,
        RENDER_H,
        spriteActual);
}