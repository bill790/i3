/*
 * vim:ts=8:expandtab
 *
 * i3 - an improved dynamic tiling window manager
 *
 * © 2009-2010 Michael Stapelberg and contributors
 *
 * See file LICENSE for license information.
 *
 */
#include "data.h"
#include <xcb/randr.h>

#ifndef _RANDR_H
#define _RANDR_H

TAILQ_HEAD(outputs_head, xoutput);
extern struct outputs_head outputs;

/**
 * We have just established a connection to the X server and need the initial
 * XRandR information to setup workspaces for each screen.
 *
 */
void initialize_randr(xcb_connection_t *conn, int *event_base);

/**
 * (Re-)queries the outputs via RandR and stores them in the list of outputs.
 *
 */
void randr_query_screens(xcb_connection_t *conn);

/**
 * Returns the first output which is active.
 *
 */
Output *get_first_output();

/**
 * Returns the output with the given name if it is active (!) or NULL.
 *
 */
Output *get_output_by_name(const char *name);

/**
 * Looks in virtual_screens for the i3Screen which contains coordinates x, y
 *
 */
Output *get_screen_containing(int x, int y);

/**
 * Gets the screen which is the last one in the given direction, for example
 * the screen on the most bottom when direction == D_DOWN, the screen most
 * right when direction == D_RIGHT and so on.
 *
 * This function always returns a screen.
 *
 */
Output *get_screen_most(direction_t direction, Output *current);

#endif
