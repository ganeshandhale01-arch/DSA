#include "event_notifier.h"

void event_initialize(Event* event)
{
    // Write your implementation here. 
    event->handlers = malloc(INIT_CAPACITY * sizeof(*event->handlers));
    event->count = 0;
    event->capacity = INIT_CAPACITY;
}
void event_deinitialize(Event* event)
{
    // Write your implementation here.
    if (event->handlers)
    {
        free(event->handlers);
    }
    event->handlers = NULL;
    event->count = 0;
    event->capacity = 0;
}

bool event_subscribe(Event* event, void (*handler)(const Event*, const void*, size_t))
{
    // Write your implementation here.
    if(event->count == event->capacity)
    {
        size_t new_capacity = event->capacity * 2;
        void (**new_handlers)(const Event*, const void*, size_t);
        
        new_handlers = realloc(event->handlers, new_capacity * sizeof(*new_handlers));
        if(new_handlers == NULL)
        {
            return false;
        }
        
        event->handlers = new_handlers;
        event->capacity = new_capacity;
    }
    event->handlers[event->count++] = handler;
    return true;
}

bool event_unsubscribe(Event* event, void (*handler)(const Event*, const void*, size_t))
{
    // Write your implementation here.
    int i, j;
    for( i = 0; i < event->count; i++)
    {
        if (event->handlers[i] == handler)
        {
            for(j = i; j < event->count - 1; j++)
            {
                event->handlers[j] = event->handlers[j+1];
            }
            event->count--;
            return true;
        }
    }
    return false;
}
void event_notify(Event* event, const void* data, size_t length)
{
    // Write your implementation here.
    int i;
    for( i = 0; i < event->count; i++)
    {
        event->handlers[i] (event, data, length);
    }
}

