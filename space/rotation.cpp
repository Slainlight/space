#include "rotation.h"
double degreesToRadians(double angleDegrees)
{
	return (angleDegrees * PI / 180.0);
}

double radiansToDegrees(double angleRadians)
{
	return angleRadians * 180.0 / PI;
}
