#ifndef STASM_LIB_H
#define STASM_LIB_H

static const int stasm_NLANDMARKS = 77; // number of landmarks

extern const char* const stasm_VERSION;

extern "C"
int stasm_init(              // call once, at bootup
    const char*  datadir,    // in: directory of face detector files
    int          trace);     // in: 0 normal use, 1 trace to stdout and stasm.log

extern "C"
int stasm_open_image(        // call once per image, detect faces
    const char*  img,        // in: gray image data, top left corner at 0,0
    int          width,      // in: image width
    int          height,     // in: image height
    const char*  imgpath,    // in: image path, used only for err msgs and debug
    int          multiface,  // in: 0=return only one face, 1=allow multiple faces
    int          minwidth);  // in: min face width as percentage of img width

extern "C"
int stasm_search_auto(       // call repeatedly to find all faces
    int*         foundface,  // out: 0=no more faces, 1=found face
    float*       landmarks); // out: x0, y0, x1, y1, ..., caller must allocate

extern "C"
int stasm_search_single(     // wrapper for stasm_search_auto and friends
    int*         foundface,  // out: 0=no face, 1=found face
    float*       landmarks,  // out: x0, y0, x1, y1, ..., caller must allocate
    const char*  img,        // in: gray image data, top left corner at 0,0
    int          width,      // in: image width
    int          height,     // in: image height
    const char*  imgpath,    // in: image path, used only for err msgs and debug
    const char*  datadir);   // in: directory of face detector files

extern "C"                   // find landmarks, no OpenCV face detect
int stasm_search_pinned(     // call after the user has pinned some points
    float*       landmarks,  // out: x0, y0, x1, y1, ..., caller must allocate
    const float* pinned,     // in: pinned landmarks (0,0 points not pinned)
    const char*  img,        // in: gray image data, top left corner at 0,0
    int          width,      // in: image width
    int          height,     // in: image height
    const char*  imgpath);   // in: image path, used only for err msgs and debug

extern "C"
const char* stasm_lasterr(void); // return string describing last error

extern "C"
void stasm_force_points_into_image( // force landmarks into image boundary
    float*       landmarks,         // io
    int          ncols,             // in
    int          nrows);            // in

extern "C"
void stasm_convert_shape( // convert stasm_NLANDMARKS points to given number of points
    float* landmarks,     // io: return all points zero if can't do conversion
    int    nlandmarks);   // in: see ConvertShape

// stasm_printf is like printf but also prints to the file stasm.log if it
// is open.  The file stasm.log will be open if stasm_init was called with
// trace=1.  This function was added primarily for the programs that test
// the stasm library.

extern "C"
void stasm_printf(const char* format, ...); // print to stdout and stasm.log

#endif // STASM_LIB_H
