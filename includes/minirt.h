/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:47:05 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/18 21:08:04 by drenassi         ###   ########.fr       */
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
# define DEPTH 3
# define PRECISION 0.01
# define DEFAULT_REFLECT_RATIO 0.0
# ifndef M_PI
#  define M_PI 3.14159265358
# endif

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
	struct s_light	*next;
}			t_light;

typedef struct s_sphere
{
	t_vector		pos;
	double			radius;
	int				color;
	double			reflect;
	struct s_sphere	*next;
}			t_sphere;

typedef struct s_plane
{
	t_vector		pos;
	t_vector		normal;
	int				color;
	double			reflect;
	struct s_plane	*next;
}			t_plane;

typedef struct s_cylinder
{
	t_vector			pos;
	t_vector			axis;
	double				radius;
	double				height;
	int					color;
	double				reflect;
	struct s_cylinder	*next;
}			t_cylinder;

typedef struct s_cone
{
	t_vector		pos;
	t_vector		axis;
	double			radius;
	double			height;
	int				color;
	double			reflect;
	struct s_cone	*next;
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
	t_alight	*a_light;
	t_camera	*camera;
	t_light		*light;
	t_plane		*planes;
	t_sphere	*spheres;
	t_cylinder	*cylinders;
	t_cone		*cones;
	t_obj		*objs;
}			t_data;

typedef struct s_minirt
{
	t_window	*win;
	t_image		*img;
	t_data		*data;
	t_vector	base[3];
	t_vector	start;
	t_vector	end;
}			t_minirt;

/* STRING UTILS */
int				ft_strcmp(const char *s1, const char *s2);
double			ft_atod(char *str);
int				double_array_len(char **array);
void			free_double_array(char **array);
int				print_error(char *msg);
int				is_empty(char *line);

/* MATHS UTILS */
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

/* COLORS UTILS */
int				format_color(char *colors_str);
void			display_loading(char *msg, int start, int pos, \
		int percent_size);
t_color			int_to_rgb(int color);
int				rgb_to_int(int r, int g, int b);
void			protect_colors(t_color *color);

/* CHECK CONFIG FILE*/
int				check_args(int ac, char **av, int *threads);
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

/* WINDOW */
t_minirt		*set_minirt(char *file);
int				exit_handling(t_minirt *mem);
t_window		*get_window(void);
void			destroy_window(t_window *win);
t_image			*get_image(t_window *win);
void			destroy_image(t_image *img, void *mlx);

/* INPUTS */
int				user_input(int keycode, t_minirt *data);

/* PARAMETERS AND SHAPES STRUCTURES AND LISTS */
t_vector		str_to_vect(char *str);
t_camera		*set_camera(t_vector pos, t_vector direction, int fov);
void			destroy_camera(t_camera *camera);
t_viewport		init_viewport(double fov, double distance);
t_alight		*set_alight(double ratio, int color);
void			destroy_alight(t_alight *alight);
void			set_light(t_light **light, t_vector pos, \
		double ratio, int color);
void			destroy_lights(t_light **light);
void			set_plane(t_plane **plane, t_vector pos_normal[2], \
		double cr[2]);
void			destroy_plane(t_plane **plane);
void			set_sphere(t_sphere **sphere, t_vector pos, double rcr[3]);
void			destroy_sphere(t_sphere **sphere);
void			set_cylinder(t_cylinder **cylinder, t_vector pos_axis[2], \
		double dhcr[4]);
void			destroy_cylinder(t_cylinder **cylinder);
void			set_cone(t_cone **cone, t_vector pos_axis[2], double rhcr[4]);
void			destroy_cone(t_cone **cone);

/* OBJECTS LIST */
t_obj			*create_new_obj(void);
t_obj			*get_last_obj(t_obj *obj);
void			init_objs(t_data *data);
void			init_objs_cone(t_data *data);
void			destroy_objs(t_obj **obj);
void			init_ray(t_data *data, t_ray *ray);

/* DATAS STRUCTURE */
char			**create_data_array(char *line);
void			set_data_shapes(t_data *data, char **datas);
t_data			*set_data(char *file);
void			destroy_data(t_data *data);

/* RAYTRACING */
t_vector		get_obj_normal(t_obj *obj, t_vector intersection);
t_vector		set_ray(t_vector base[3], double x, double y, double z);
t_vector		intersection_point(t_ray ray, double distance);
double			cy_intersection(t_ray ray, t_cylinder *cylinder);
double			cone_intersection(t_ray ray, t_cone *co);
double			obj_intersection(t_ray ray, t_obj *obj);
t_closest_obj	closest_intersection(t_data *data, t_ray ray);
t_color			ray_trace(t_data *data, t_ray ray, int depth);

/* AMBIENT LIGHTNING */
t_vector		ambient_lightning_intensity(t_data *data);

/* LIGHT */
t_vector		light_intensity(t_light light);

/* LIGHT EFFECTS */
t_color			get_obj_color(t_obj *obj);
double			get_obj_reflect_ratio(t_obj *obj);
t_vector		reflection_dir(t_vector normal, t_vector dir);
t_color			reflection_color(t_color color, t_color reflective, \
		double ratio);
t_color			light_effects(t_data *data, t_vector normal, \
		t_closest_obj closest, t_ray ray);
int				is_in_shadow(t_data *data, t_vector point, t_light light);
int				is_on_cone(t_cone co, t_vector p);
double			shadow_effects(t_data *data, t_vector inter, \
		t_closest_obj closest);

/* RENDERING */
void			rendering(t_minirt *mem, int threads, char *file);
void			draw_pixels(t_image *img, int x, int y, int color);

#endif