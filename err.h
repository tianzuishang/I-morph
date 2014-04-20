// err.h: error handling for Stasm
//


#ifndef STASM_ERR_H
#define STASM_ERR_H

namespace stasm
{
void CatchOpenCvErrs(void);
void UncatchOpenCvErrs(void);
void Err(const char* format, ...);
void ClearLastErr(void);
const char* LastErr(void); // return the last error message

} // namespace stasm
#endif // STASM_ERR_H
