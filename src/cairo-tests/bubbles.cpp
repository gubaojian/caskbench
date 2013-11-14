#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>

#include "caskbench.h"

static int max_dim;

int
ca_setup_bubbles(caskbench_context_t *ctx)
{
  max_dim = MIN(ctx->canvas_width, ctx->canvas_height)/2;
  return 1;
}

void
ca_teardown_bubbles(void)
{
}

int
ca_test_bubbles(caskbench_context_t *ctx)
{
  int i, x, y, r;

  for (i=0; i<ctx->size; i++) {
    r = ((double)max_dim*rand())/RAND_MAX + 1;
    x = (0.5*(double)ctx->canvas_width*rand())/RAND_MAX;
    y = (0.5*(double)ctx->canvas_height*rand())/RAND_MAX;
    randomize_color (ctx->cr);
    cairo_arc (ctx->cr, x, y, r, 0, 2*M_PI);
    cairo_fill (ctx->cr);
  }

  return 1;
}