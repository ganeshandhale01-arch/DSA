/**
 * @file shape.c
 * @brief Optimized implementation of shape objects using the Factory Pattern.
 * @details This module provides concrete implementations of various shape types
 *          with optimizations: removed memset, static vtables, unified initialization.
 * @author Your Name
 * @date December 8, 2025
 * @version 2.0 (Optimized)
 */

#include "shape.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @def CONTAINER_OF
 * @brief Macro to get the parent structure from a member pointer.
 * @details Calculates the address of the containing structure given a pointer
 *          to one of its members. This is a common kernel programming idiom.
 * @param ptr Pointer to the member.
 * @param type Type of the container structure.
 * @param member Name of the member within the container.
 * @return Pointer to the container structure.
 */
#define CONTAINER_OF(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

/* ============================================================================
 * Shape Structure Definitions
 * ============================================================================ */

/**
 * @struct shape_circle
 * @brief Concrete implementation of a circle shape.
 */
struct shape_circle
{
    struct shape shape;  /**< Base shape structure (must be first member) */
    float radius;        /**< Radius of the circle */
};

/**
 * @struct shape_rectangle
 * @brief Concrete implementation of a rectangle shape.
 */
struct shape_rectangle
{
    struct shape shape;  /**< Base shape structure (must be first member) */
    float width;         /**< Width of the rectangle */
    float height;        /**< Height of the rectangle */
};

/**
 * @struct shape_triangle
 * @brief Concrete implementation of a triangle shape.
 */
struct shape_triangle
{
    struct shape shape;  /**< Base shape structure (must be first member) */
    float base;          /**< Base length of the triangle */
    float height;        /**< Height of the triangle */
};

/**
 * @struct shape_square
 * @brief Concrete implementation of a square shape.
 */
struct shape_square
{
    struct shape shape;  /**< Base shape structure (must be first member) */
    float side;          /**< Side length of the square */
};

/* ============================================================================
 * Shape Draw Implementations
 * ============================================================================ */

/**
 * @brief Draw function implementation for circle shapes.
 * @param shape Opaque handle to the circle shape.
 */
static void shape_circle_draw(shape_t shape)
{
    struct shape_circle *self = CONTAINER_OF(shape, struct shape_circle, shape.method);
    printf("Drawing circle with radius: %.2f\n", self->radius);
}

/**
 * @brief Draw function implementation for rectangle shapes.
 * @param shape Opaque handle to the rectangle shape.
 */
static void shape_rectangle_draw(shape_t shape)
{
    struct shape_rectangle *self = CONTAINER_OF(shape, struct shape_rectangle, shape.method);
    printf("Drawing rectangle with width: %.2f and height: %.2f\n", self->width, self->height);
}

/**
 * @brief Draw function implementation for triangle shapes.
 * @param shape Opaque handle to the triangle shape.
 */
static void shape_triangle_draw(shape_t shape)
{
    struct shape_triangle *self = CONTAINER_OF(shape, struct shape_triangle, shape.method);
    printf("Drawing triangle with base: %.2f and height: %.2f\n", self->base, self->height);
}

/**
 * @brief Draw function implementation for square shapes.
 * @param shape Opaque handle to the square shape.
 */
static void shape_square_draw(shape_t shape)
{
    struct shape_square *self = CONTAINER_OF(shape, struct shape_square, shape.method);
    printf("Drawing square with side: %.2f\n", self->side);
}

/* ============================================================================
 * Static Virtual Method Tables (vtables)
 * ============================================================================ */

/** @brief Virtual method table for circle operations. */
static const struct shape_method circle_method = {
    .draw = shape_circle_draw,
};

/** @brief Virtual method table for rectangle operations. */
static const struct shape_method rectangle_method = {
    .draw = shape_rectangle_draw,
};

/** @brief Virtual method table for triangle operations. */
static const struct shape_method triangle_method = {
    .draw = shape_triangle_draw,
};

/** @brief Virtual method table for square operations. */
static const struct shape_method square_method = {
    .draw = shape_square_draw,
};

/* ============================================================================
 * Public API Implementation
 * ============================================================================ */

/**
 * @brief Draw any shape.
 * @param shape Opaque handle to the shape object.
 */
void shape_draw(shape_t shape)
{
    if (shape && *shape && (*shape)->draw) {
        (*shape)->draw(shape);
    }
}

/**
 * @brief Unified factory function to create shape objects.
 * @details Optimized with compound literals for initialization.
 * @param type The type of shape to create.
 * @return shape_t Handle to the created shape, or NULL on failure.
 */
shape_t shape_create(enum shape_type type)
{
    switch (type)
    {
        case CIRCLE:
        {
            struct shape_circle *circle = malloc(sizeof(*circle));
            if (!circle) return NULL;
            
            *circle = (struct shape_circle){
                .shape.method = &circle_method,
                .radius = 10.0f
            };
            return (shape_t)&circle->shape.method;
        }
        
        case RECTANGLE:
        {
            struct shape_rectangle *rectangle = malloc(sizeof(*rectangle));
            if (!rectangle) return NULL;
            
            *rectangle = (struct shape_rectangle){
                .shape.method = &rectangle_method,
                .width = 20.0f,
                .height = 10.0f
            };
            return (shape_t)&rectangle->shape.method;
        }
        
        case TRIANGLE:
        {
            struct shape_triangle *triangle = malloc(sizeof(*triangle));
            if (!triangle) return NULL;
            
            *triangle = (struct shape_triangle){
                .shape.method = &triangle_method,
                .base = 15.0f,
                .height = 10.0f
            };
            return (shape_t)&triangle->shape.method;
        }
        
        case SQUARE:
        {
            struct shape_square *square = malloc(sizeof(*square));
            if (!square) return NULL;
            
            *square = (struct shape_square){
                .shape.method = &square_method,
                .side = 10.0f
            };
            return (shape_t)&square->shape.method;
        }
        
        default:
            return NULL;
    }
}

/**
 * @brief Destroy and free a shape object.
 * @param shape Handle to the shape object to destroy.
 */
void shape_destroy(shape_t shape)
{
    if (shape && *shape) {
        struct shape *base = CONTAINER_OF(*shape, struct shape, method);
        free(base);
    }
}