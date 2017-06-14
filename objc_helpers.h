//
// Created by Ed Halferty on 6/14/17.
//

#ifndef UML_VIEWER_01_OBJC_HELPERS_H
#define UML_VIEWER_01_OBJC_HELPERS_H


// Copied from <AppKit/NSWindow.h>
enum {
    NSBorderlessWindowMask = 0,
    NSTitledWindowMask = 1 << 0,
    NSClosableWindowMask = 1 << 1,
    NSMiniaturizableWindowMask = 1 << 2,
    NSResizableWindowMask	= 1 << 3,
    NSTexturedBackgroundWindowMask = 1 << 8,
    NSUnifiedTitleAndToolbarWindowMask = 1 << 12,
    NSFullScreenWindowMask = 1 << 14,
    NSFullSizeContentViewWindowMask = 1 << 15
};


// Copied from <AppKit/NSGraphics.h>
typedef CF_ENUM(unsigned long, NSBackingStoreType) {
    NSBackingStoreRetained = 0,
    NSBackingStoreNonretained = 1,
    NSBackingStoreBuffered = 2
};


// Copied from <AppKit/NSOpenGL.h>
enum {
    NSOpenGLPFADoubleBuffer = 5
};
typedef uint32_t NSOpenGLPixelFormatAttribute;

// Common objc_msgSend call patterns
#define sendNoArgs(i, f) objc_msgSend(i, sel_registerName(f))
#define send(i, f, ...) objc_msgSend(i, sel_registerName(f), __VA_ARGS__)
#define sendClass(c, f, ...)\
    objc_msgSend((id)objc_getClass(c), sel_registerName(f), ...)
#define sendClassNoArgs(c, f)\
    objc_msgSend((id)objc_getClass(c), sel_registerName(f))
#define alloc(c) sendClassNoArgs(c, "alloc")
#define init(i) sendNoArgs(i, "init")
#define initAlloc(c) init(alloc(c))
#define addMethod(c, m, ...)\
    class_addMethod(c, sel_registerName(m), __VA_ARGS__)
#define allocateClassPair(s, n, e)\
    objc_allocateClassPair((Class)objc_getClass(s), n, e)
#define allocateClassPairNoExtra(s, n)\
    objc_allocateClassPair((Class)objc_getClass(s), n, 0)

#endif //UML_VIEWER_01_OBJC_HELPERS_H