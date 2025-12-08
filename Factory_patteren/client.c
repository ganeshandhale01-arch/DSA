/**
 * @file client.c
 * @brief Client code demonstrating the Shape Factory Pattern.
 * @details Creates various shape objects using the factory function and
 *          demonstrates polymorphic behavior through the shape_draw() function.
 * @author Your Name
 * @date December 8, 2025
 * @version 1.0
 */

#include "shape.h"

/**
 * @brief Main function demonstrating factory pattern usage.
 * @details Creates four different shape types using the factory function
 *          and draws each one, showcasing polymorphic behavior.
 * @return int Exit status (0 for success).
 */
int main() 
{
    // Create different shape objects using the factory
    shape_t circle = shape_create(CIRCLE);
    shape_t rectangle = shape_create(RECTANGLE);
    shape_t triangle = shape_create(TRIANGLE);
    shape_t square = shape_create(SQUARE);
    
    // Draw all shapes - polymorphic behavior in action
    shape_draw(circle);      // Calls circle's draw implementation
    shape_draw(rectangle);   // Calls rectangle's draw implementation
    shape_draw(triangle);    // Calls triangle's draw implementation
    shape_draw(square);      // Calls square's draw implementation

    // Note: Memory cleanup implemented
    shape_destroy(circle);
    shape_destroy(rectangle);   
    shape_destroy(triangle);    
    shape_destroy(square);

    return 0;
}