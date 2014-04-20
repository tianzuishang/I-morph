// eyedist.h: calculate eye-mouth and inter-eye dist
//


#ifndef STASM_EYEDIST_H
#define STASM_EYEDIST_H

namespace stasm
{
double EyeMouthDist(     // eye-mouth distance of a face shape
    const Shape& shape); // in

double InterEyeDist(     // inter-pupil distance of a face shape
    const Shape& shape); // in:

} // namespace stasm
#endif // STASM_EYEDIST_H
