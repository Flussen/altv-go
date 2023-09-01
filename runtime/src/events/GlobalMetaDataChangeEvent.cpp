#include "GlobalMetaDataChangeEvent.h"
#include "GoRuntime.h"

Go::GlobalMetaDataChangeEvent::GlobalMetaDataChangeEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::GlobalMetaDataChangeEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altGlobalMetaDataChangeEvent", void (*)(const char* key, CArray oldValue, CArray newValue));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Could not call GlobalMetaDataChangeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CGlobalMetaDataChangeEvent *>(ev);
    auto key = event->GetKey().c_str();
    auto newValueMeta = event->GetVal();
    auto oldValueMeta = event->GetOldVal();

    auto oldV = Go::Runtime::EncodeMValue(oldValueMeta);
    auto newV = Go::Runtime::EncodeMValue(newValueMeta);

    call(key, oldV, newV);

    // TODO: free Arrays
}
