/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:47:05 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/28 16:46:33 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# define SCREEN_H 810
# define SCREEN_W 1440
# define VIEWPORT_DIST 1
# define DEPTH 5
# define PRECISION 0.01
# define DEFAULT_REFLECT_RATIO 0.0
# define ANTI_ALIASING 0.8
# ifndef M_PI
#  define M_PI 3.14159265358
# endif

/********************************* STRUCTURES *********************************/
typedef struct s_window
{
	void	*mlx;
	void	*window;
}			t_window;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	sum;
}			t_color;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

typedef struct s_alight
{
	double	ratio;
	int		color;
}			t_alight;

typedef struct s_camera
{
	t_vector	pos;
	t_vector	direction;
	int			fov;
	t_vector	base[3];
}			t_camera;

typedef struct s_viewport
{
	double	w;
	double	w_ratio;
	double	h;
	double	h_ratio;
}			t_viewport;

typedef struct s_light
{
	t_vector		pos;
	double			ratio;
	int				color;
}			t_light;

typedef struct s_map
{
	t_color	**color;
	int		w;
	int		h;
}			t_map;

typedef struct s_plane
{
	t_vector		pos;
	t_vector		normal;
	int				color;
	double			reflect;
	t_vector		base[3];
	t_map			normal_map;
	t_map			texture;
}			t_plane;

typedef struct s_sphere
{
	t_vector		pos;
	double			radius;
	int				color;
	double			reflect;
	t_vector		base[3];
	t_map			normal_map;
	t_map			texture;
}			t_sphere;

typedef struct s_cylinder
{
	t_vector			pos;
	t_vector			axis;
	double				radius;
	double				height;
	int					color;
	double				reflect;
	t_vector			base[3];
	t_map				normal_map;
	t_map				texture;
}			t_cylinder;

typedef struct s_cone
{
	t_vector		pos;
	t_vector		axis;
	double			radius;
	double			height;
	int				color;
	double			reflect;
	t_vector		base[3];
	t_map			normal_map;
	t_map			texture;
}			t_cone;

typedef struct s_obj
{
	t_plane			*pl;
	t_sphere		*sp;
	t_cylinder		*cy;
	t_cone			*co;
	t_light			*light;
	struct s_obj	*next;
}			t_obj;

typedef struct s_closest_obj
{
	t_obj	*obj;
	double	distance;
	double	reflect;
}			t_closest_obj;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dir;
}			t_ray;

typedef struct s_data
{
	t_alight	a_light;
	t_camera	camera;
	t_obj		*objs;
	t_ray		ray;
}			t_data;

typedef struct s_minirt
{
	t_window	win;
	t_image		img;
	t_viewport	vp;
	t_data		data;
	t_vector	start;
	t_vector	end;
}			t_minirt;

/*********************************** UTILS ************************************/
/* STRING UTILS */
int				ft_strcmp(const char *s1, const char *s2);
double			ft_atod(char *str);
int				double_array_len(char **array);
void			free_double_array(char **array);
int				print_error(char *msg);
int				is_empty(char *line);

/* MATHS UTILS */
t_vector		str_to_vect(char *str);
double			vect_length(t_vector vect);
t_vector		normalize_vect(t_vector vect);
t_vector		add_vect(t_vector vect1, t_vector vect2);
t_vector		substract_vect(t_vector vect1, t_vector vect2);
t_vector		multiply_vect(t_vector	v1, t_vector v2);
t_vector		divide_vect(t_vector	v1, t_vector v2);
t_vector		multiply_vect_scalar(t_vector vect, double scalar);
double			vect_dot(t_vector v1, t_vector v2);
t_vector		vect_cross_product(t_vector v1, t_vector v2);
double			vect_cos(t_vector v1, t_vector v2);
double			vect_sin(t_vector v1, t_vector v2);
t_vector		rotate_vect(t_vector vector, t_vector axis, \
		double cos, double sin);
void			rotate_base(t_vector base[3], t_vector direction);
double			quadratic(double a, double b, double c, int sol);
double			matrix_det(t_vector m[3]);
t_vector		multiply_vect_matrix(t_vector v, t_vector m[3]);
void			transpose_matrix(t_vector m[3]);
void			inverse_matrix(t_vector m[3]);
t_vector		sphere_tangent(double radius, double theta, double phi);
t_vector		cylinder_tangent(t_cylinder cylinder, \
		t_vector point, double theta);
t_vector		cone_tangent(t_cone cone, t_vector point, double theta);

/* COLORS UTILS */
int				format_color(char *colors_str);
void			display_loading(char *msg, int start, int pos, \
		int percent_size);
t_color			int_to_rgb(int color);
int				rgb_to_int(int r, int g, int b);
void			protect_colors(t_color *color);

/********************************* CHECK FILE *********************************/
/* CHECK CONFIG FILE*/
int				check_args(int ac, char **av, int *threads, int *anti_aliasing);
int				check_file(char *file);
int				check_identifier(char *line);
int				check_int(char *n);
int				check_double(char *f);
int				check_rgb(char *param);
int				check_coordinates(char *coord);
int				check_orientation_vector(char *coord);
int				check_ambiant_lightning(char **data);
int				check_camera(char **data);
int				check_light(char **data);
int				check_plane(char **data);
int				check_sphere(char **data);
int				check_cylinder(char **data);
int				check_cone(char **data);

/******************************* INITIALIZATION *******************************/
/* INPUTS */
int				user_input(int keycode, t_minirt *data);

/* WINDOW */
t_minirt		*set_minirt(char *file);
int				exit_handling(t_minirt *mem);
int				init_window(t_window *win);
void			destroy_window(t_window *win);
int				init_image(t_image *img, t_window win);
void			destroy_image(t_image *img, void *mlx);

/* INIT AMBIANT LIGHTNING, CAMERA AND VIEWPORT */
t_alight		set_alight(double ratio, int color);
t_camera		set_camera(t_vector pos, t_vector direction, int fov);
t_viewport		init_viewport(double fov, double distance);

/* OBJECTS LIST */
t_obj			*create_new_obj(void);
t_obj			*get_last_obj(t_obj *obj);
t_light			*create_light(t_vector pos, double ratio, int color);
void			add_light(t_data *data, t_light *light);
t_plane			*create_plane(t_vector pos_normal[2], \
		double cr[2], char *map[2]);
void			add_plane(t_data *data, t_plane *plane);
t_sphere		*create_sphere(t_vector pos, double rcr[3], char *map[2]);
void			add_sphere(t_data *data, t_sphere *sphere);
t_cylinder		*create_cylinder(t_vector pos_axis[2], \
		double dhcr[4], char *map[2]);
void			add_cylinder(t_data *data, t_cylinder *cylinder);
t_cone			*create_cone(t_vector pos_axis[2], \
		double rhcr[4], char *map[2]);
void			add_cone(t_data *data, t_cone *cone);
void			destroy_objs(t_obj **obj);

/* INIT BUMP MAPPING */
t_map			create_map(char *file_path);
void			destroy_map(t_map *map);

/* DATAS STRUCTURE */
char			**create_data_array(char *line);
void			set_data_shapes(t_data *data, char **datas);
t_vector		set_ray(t_vector base[3], double x, double y, double z);
t_data			set_data(char *file);
void			destroy_data(t_data *data);

/******************************* LIGHT EFFECTS ********************************/
/* AMBIENT LIGHTNING INTENSITY*/
t_vector		ambient_lightning_intensity(t_alight a_light, double property);

/* LIGHT INTENSITY*/
t_vector		light_intensity(t_light light, double lambertian);

/* DIFFUSE INTENSITY */
t_vector		diffuse_intensity(t_vector normal, \
		t_vector p_to_l, t_vector light);

/* SPECULAR INTENSITY */
t_vector		specular_intensity(t_vector p_to_l, t_vector normal, \
		t_vector light);

/* SHADOWS */
int				is_in_shadow(t_obj *obj, t_vector point, t_light light);

/* REFLECTION */
double			get_obj_reflect_ratio(t_obj *obj);
t_vector		reflection_dir(t_vector normal, t_vector dir);
t_color			reflection_color(t_color color, t_color reflective, \
		double ratio, double cap);

/* LIGHT EFFECTS */
t_color			get_obj_color(t_obj *obj, t_vector point, t_vector normal);
t_color			light_effects(t_data *data, t_vector normal, \
		t_closest_obj current, t_ray ray);

/******************************** BUMP MAPPING ********************************/
/* MAPPING */
t_color			plane_mapping(t_plane plane, t_map map, \
		t_vector point, int ratio);
t_color			sphere_mapping(t_sphere sphere, t_map map, t_vector normal);
t_color			cylinder_mapping(t_cylinder cylinder, t_map map, \
		t_vector point, t_vector normal);
t_color			cone_mapping(t_cone cone, t_map map, \
		t_vector point, t_vector normal);

/* BUMP NORMALS */
t_vector		bump_normal(t_obj *obj, t_vector point, t_vector normal);

/********************************* RAYTRACING *********************************/
/* INTERSECTIONS */
t_vector		intersection_point(t_ray ray, double distance);
double			pl_intersection(t_ray ray, t_plane pl);
double			sp_intersection(t_ray ray, t_sphere sp);
double			cy_intersection(t_ray ray, t_cylinder cylinder);
double			cone_intersection(t_ray ray, t_cone co);
double			obj_intersection(t_ray ray, t_obj *obj);
t_closest_obj	closest_intersection(t_obj *objs, t_ray ray);
int				is_on_obj(t_obj obj, t_vector point);

/* NORMALS */
t_vector		get_obj_normal(t_obj *obj, t_vector intersection, t_ray ray);
t_color			ray_trace(t_data *data, t_ray ray, int depth);

/********************************* RENDERING **********************************/
void			draw_pixels(t_image *img, int x, int y, int color);
t_color			get_pixel_color(t_image img, int x, int y);
void			anti_aliasing(t_minirt *mem, double ratio);
void			rendering(t_minirt *mem, int threads, int a_aliasing);

#endif