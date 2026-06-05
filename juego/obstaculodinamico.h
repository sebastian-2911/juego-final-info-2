#ifndef OBSTACULODINAMICO_H
#define OBSTACULODINAMICO_H

#include "obstaculo.h"
#include <QPixmap>

// ── Tipos de obstáculo dinámico ──────────────────────────────
// Usa una animación simple de hasta 3 frames.
// Hereda toda la lógica de colisión y movimiento de Obstaculo.

enum TipoDinamico
{
    OBS_SOLDADO,
    OBS_RHAEGAR
};

class ObstaculoDinamico : public Obstaculo
{
public:
    ObstaculoDinamico(float x,
                      float yReal,
                      TipoDinamico tipo,
                      int carril);

    void actualizar() override;

    void renderizar(QPainter& painter) override;
    void renderizar(QPainter& painter,
                    float scrollMundo) override;

private:
    TipoDinamico tipoDinamico;

    QPixmap sprites[3];

    int frameActual;
    int contadorAnimacion;

    bool mirarDerecha;

    static constexpr int RENDER_W = 200;
    static constexpr int RENDER_H = 320;
};

#endif // OBSTACULODINAMICO_H