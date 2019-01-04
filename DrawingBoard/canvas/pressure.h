#ifndef CANVAS_PRESSURE_H
#define CANVAS_PRESSURE_H

#include "utils/kis_cubic_curve.h"

struct PressureMapping {
	enum Mode {
		STYLUS, // real tablet pressure info, no parameter
		DISTANCE, // param=max distance
		VELOCITY // param=max velocity
	};

	Mode mode;
	KisCubicCurve curve;
	qreal param;

	PressureMapping() : mode(STYLUS), param(1.0) { }
};

Q_DECLARE_METATYPE(PressureMapping)

#endif

