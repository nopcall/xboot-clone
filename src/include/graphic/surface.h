#ifndef __SURFACE_H__
#define __SURFACE_H__

#include <xboot.h>
#include <graphic/color.h>
#include <graphic/pixel.h>
#include <graphic/rect.h>
#include <graphic/maps.h>

enum surface_pixels {
	SURFACE_PIXELS_NEEDFREE	= 0x0,
	SURFACE_PIXELS_DONTFREE	= 0x1,
};

/*
 * The GIMP c-source image
 */
struct gimage
{
	/* the width of image */
	u32_t width;

	/* the height of image */
	u32_t height;

	/*
	 * bytes per pixel
	 * 3:RGB  - PIXEL_FORMAT_BGR_888
	 * 4:RGBA - PIXEL_FORMAT_ABGR_8888
	 */
	u32_t bytes_per_pixel;

	/* pixel data */
	u8_t * pixels;
};

struct surface_t {
	/* surface pixel information */
	struct pixel_info info;

	/* surface's width and height */
	u32_t w, h;

	/* pitch of one scan line */
	u32_t pitch;

	/* surface pixels flag */
	enum surface_pixels flag;

	/* pointer to pixel data */
	void * pixels;

    /* clipping information */
	struct rect_t clip;

	/* surface map functions */
	struct surface_maps maps;

	/* private data */
	void * pirv;
};


struct surface_t * surface_alloc(void * pixels, u32_t w, u32_t h, enum pixel_format fmt);
struct surface_t * surface_alloc_from_gimage(const struct gimage * image);
void surface_free(struct surface_t * surface);

bool_t surface_set_clip_rect(struct surface_t * surface, struct rect_t * rect);
bool_t surface_get_clip_rect(struct surface_t * surface, struct rect_t * rect);
u32_t surface_map_color(struct surface_t * surface, struct color_t * col);
void surface_unmap_color(struct surface_t * surface, u32_t c, struct color_t * col);
bool_t surface_draw_points(struct surface_t * surface, const struct point_t * points, u32_t count, u32_t c);
bool_t surface_draw_lines(struct surface_t * surface, const struct point_t * points, u32_t count, u32_t c);
bool_t surface_fill_rects(struct surface_t * surface, const struct rect_t * rects, u32_t count, u32_t c);
bool_t surface_blit(struct surface_t * dst, struct rect_t * dst_rect, struct surface_t * src, struct rect_t * src_rect, enum blit_mode mode);

#endif /* __SURFACE_H__ */