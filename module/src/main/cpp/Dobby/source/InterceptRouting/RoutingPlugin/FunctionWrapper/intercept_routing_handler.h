#ifndef FUNCTION_WRAPPER_INTERCEPT_ROUTING_HANDLER_H
#define FUNCTION_WRAPPER_INTERCEPT_ROUTING_HANDLER_H

#include "TrampolineBridge/ClosureTrampolineBridge/AssemblyClosureTrampoline.h"
#include "Interceptor.h"
#include "dobby_internal.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

// Dispatch the routing befor running the origin function
void prologue_routing_dispatch(RegisterContext *ctx, ClosureTrampolineEntry *entry);

// Dispatch the routing before the function return . (as it's implementation by replace `return address` in the stack
// ,or LR register)
void epilogue_routing_dispatch(RegisterContext *ctx, ClosureTrampolineEntry *entry);

void pre_call_forward_handler(RegisterContext *ctx, HookEntry *entry);

void post_call_forward_handler(RegisterContext *ctx, HookEntry *entry);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif