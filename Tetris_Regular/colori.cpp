#include "colori.h"


const Color grigioScuro = { 26, 31, 40, 255 };
const Color verde = { 47, 230, 23, 255 };
const Color rosso = { 232, 18, 18, 255 };
const Color arancione = { 226, 116, 17, 255 };
const Color giallo = { 237, 234, 4, 255 };
const Color viola = { 166, 0, 247, 255 };
const Color ciano = { 21, 204, 209, 255 };
const Color blu = { 13, 64, 216, 255 };
const Color bluChiaro = { 59, 85, 162, 255 };
const Color bluScuro = { 44, 44, 127, 255 };

std::vector<Color> OttieniColoreCella() {

	return { grigioScuro, verde, rosso, arancione, giallo, viola, ciano, blu };
}