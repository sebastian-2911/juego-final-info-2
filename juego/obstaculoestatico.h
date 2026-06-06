#ifndef OBSTACULOESTATICO_H
#define OBSTACULOESTATICO_H

#include "obstaculo.h"
#include <QPixmap>

// ── Tipos de obstáculo estático ──────────────────────────────
// Sprite fijo, sin animación. Solo se dibuja el QPixmap cargado.
// Hereda toda la lógica de colisión y movimiento de Obstaculo.
enum TipoEstatico
{
    OBS_PIEDRA,
    OBS_CADAVER
};

class ObstaculoEstatico : public Obstaculo
{
public:
    ObstaculoEstatico(float x, float yReal, TipoEstatico tipo);

    void renderizar(QPainter& painter) override;
    void renderizar(QPainter& painter, float scrollMundo) override;

private:
    TipoEstatico tipoEstatico;
    QPixmap sprite;

    // Tamaño de render en pantalla (px)
    static constexpr int RENDER_W = 160;
    static constexpr int RENDER_H = 160;
};

#endif // OBSTACULOESTATICO_H