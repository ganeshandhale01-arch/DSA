/**
 * @file shape.h
 * @brief Public API for Shape Factory Pattern implementation.
 * @details This header defines the interface for creating and manipulating
 *          various shape objects using the Factory design pattern in C.
 *          It provides polymorphic behavior through function pointers.
 * @author Your Name
 * @date December 8, 2025
 * @version 1.0
 */

#ifndef SHAPE_H
#define SHAPE_H

/**
 * @enum shape_type
 * @brief Enumeration of available shape types.
 * @details Used by the factory function to create specific shape instances.
 */
enum shape_type 
{
    CIRCLE,      /**< Circle shape type */
    RECTANGLE,   /**< Rectangle shape type */
    TRIANGLE,    /**< Triangle shape type */
    SQUARE       /**< Square shape type */
};

/**
 * @typedef shape_t
 * @brief Opaque handle to a shape object.
 * @details This is a double pointer to shape_method structure, providing
 *          encapsulation and preventing direct access to internal data.
 *          Users manipulate shapes only through this handle.
 */
typedef struct shape_method ** shape_t;

/**
 * @struct shape_method
 * @brief Virtual function table (vtable) for shape operations.
 * @details Contains function pointers to shape-specific implementations,
 *          enabling polymorphic behavior at runtime.
 */
struct shape_method 
{
    /**
     * @brief Function pointer to draw the shape.
     * @param shape Handle to the shape object to be drawn.
     */
    void (*draw)(shape_t shape);
};

/**
 * @struct shape
 * @brief Base structure for all shape types.
 * @details Contains a const pointer to the shape's method table.
 *          This structure is embedded in concrete shape implementations.
 */
struct shape 
{
    const struct shape_method * method;  /**< Pointer to shape's vtable (immutable) */
};

/**
 * @brief Factory function to create shape objects.
 * @details Allocates memory and initializes a shape object based on the
 *          specified type. Uses the Factory Pattern to abstract object creation.
 * @param type The type of shape to create (CIRCLE, RECTANGLE, TRIANGLE, SQUARE).
 * @return shape_t Handle to the newly created shape object, or NULL on failure.
 * @note The caller is responsible for freeing the allocated memory.
 * @warning Memory leak possible if shape is not properly destroyed.
 */
shape_t shape_create(enum shape_type type);

/**
 * @brief Draw the specified shape.
 * @details Calls the appropriate draw implementation based on the shape's type.
 *          This function demonstrates polymorphic behavior through function pointers.
 * @param shape Handle to the shape object to be drawn.
 * @note If shape is NULL or draw function pointer is NULL, no action is taken.
 */
void shape_draw(shape_t shape);

/**
 * @brief Destroy and free a shape object.
 * @details Frees the memory allocated for the shape object.
 * @param shape Handle to the shape object to destroy.
 */
void shape_destroy(shape_t shape);

#endif // SHAPE_H