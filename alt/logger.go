package alt

// #cgo LDFLAGS: -ldl
// #include <stdlib.h>
// #include "Module.h"
import "C"
import "unsafe"

//"github.com/shockdev04/altv-go-pkg/internal/module"
//"unsafe"

func LogInfo(msg string) {
	cstr := C.CString(msg)
	defer C.free(unsafe.Pointer(cstr))
	//module.Call("Core_LogInfo", uintptr(unsafe.Pointer(cstr)))
	C.log_info(cstr)
}
