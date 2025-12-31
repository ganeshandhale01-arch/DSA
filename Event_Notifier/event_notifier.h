#ifndef EVENT_NOTIFIER_H
#define EVENT_NOTIFIER_H

#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define INIT_CAPACITY    16
typedef struct Event
{
    // Create fileds of this struct as you need.
    void (**handlers)(const struct Event*, const void*, size_t);
    size_t count;
    size_t capacity;
}Event;

void event_initialize(Event* event);
void event_deinitialize(Event* event);
bool event_subscribe(Event* event, void (*handler)(const Event*, const void*, size_t));
bool event_unsubscribe(Event* event, void (*handler)(const Event*, const void*, size_t));
void event_notify(Event* event, const void* data, size_t length);

#ifdef __cplusplus
}
#endif

#endif // EVENT_NOTIFIER_H
