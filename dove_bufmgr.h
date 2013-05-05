#ifndef DRM_DOVE_GEM_H
#define DRM_DOVE_GEM_H

enum drm_dove_bo_type {
	DRM_DOVE_BO_DUMB,
	DRM_DOVE_BO_LINEAR,
	DRM_DOVE_BO_SHMEM
};

struct drm_dove_bo {
	uint32_t ref;
	uint32_t handle;
	uint32_t size;
	uint32_t pitch;
	uint32_t phys;
	void *ptr;
	enum drm_dove_bo_type type;
};

struct drm_dove_bo *drm_dove_bo_create(int fd, unsigned w, unsigned h, unsigned bpp);
struct drm_dove_bo *drm_dove_bo_create_phys(int fd, uint32_t phys, size_t size);
struct drm_dove_bo *drm_dove_bo_dumb_create(int fd, unsigned w, unsigned h,
    unsigned bpp);

/* Create a BO from a global name */
struct drm_dove_bo *drm_dove_bo_create_from_name(int fd, uint32_t name);

/* Create a global name from a BO */
int drm_dove_bo_flink(int fd, struct drm_dove_bo *bo, uint32_t *name);

int drm_dove_bo_map(int fd, struct drm_dove_bo *bo);
uint32_t drm_dove_bo_phys(int fd, struct drm_dove_bo *bo);
void drm_dove_bo_get(int fd, struct drm_dove_bo *bo);
void drm_dove_bo_put(int fd, struct drm_dove_bo *bo);
int drm_dove_bo_subdata(int fd, struct drm_dove_bo *bo, unsigned long offset,
    unsigned long size, const void *data);

#endif
