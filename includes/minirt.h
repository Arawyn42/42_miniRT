/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:47:05 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/09 19:50:49 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# define SCREEN_H 540
# define SCREEN_W 960
# define VIEWPORT_DIST 1
# define DEPTH 3
# define PRECISION 0.01
# define DEFAULT_SPECULAR_POWER -1.0
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
	t_vector	pos;
	double		ratio;
	int			color;
}			t_light;

typedef struct s_sphere
{
	t_vector		pos;
	double			radius;
	int				color;
	double			reflect;
	double			specular;
	struct s_sphere	*next;
}			t_sphere;

typedef struct s_plane
{
	t_vector		pos;
	t_vector		normal;
	int				color;
	double			reflect;
	double			specular;
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
	double				specular;
	struct s_cylinder	*next;
}			t_cylinder;

typedef struct s_obj
{
	t_plane			*pl;
	t_sphere		*sp;
	t_cylinder		*cy;
	t_light			*light;
	struct s_obj	*next;
}			t_obj;

typedef struct s_closest_obj
{
	t_obj	*obj;
	double	distance;
	double	specular;
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
	t_sphere	*spheres;
	t_plane		*planes;
	t_obj		*objs;
	t_cylinder	*cylinders;
}			t_data;

typedef struct s_minirt
{
	t_window	*win;
	t_image		*img;
	t_data		*data;
}			t_minirt;

typedef struct s_values
{
	double	farest_obj;
	int		half_screen_h;
	int		half_screen_w;
}			t_values;

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
double			quadratic_min(double a, double b, double c, double min);

/* COLORS UTILS */
int				format_color(char *colors_str);
void			display_loading(char *msg, int start, int pos, \
		int percent_size);
t_color			int_to_rgb(int color);
int				rgb_to_int(int r, int g, int b);
void			protect_colors(t_color *color);

/* CHECK CONFIG FILE*/
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

/* WINDOW */
t_minirt		*init_mem(void);
int				exit_handling(t_minirt *mem);
t_window		*get_window(void);
void			destroy_window(t_window *win);
t_image			*get_image(t_window *win);
void			destroy_image(t_image *img, void *mlx);

/* INPUTS */
int				user_input(int keycode, t_minirt *data);

/* PARAMETERS AND SHAPES STRUCTURES AND LISTS */
t_vector		str_to_point(char *str);
t_camera		*set_camera(t_vector pos, t_vector direction, int fov);
void			destroy_camera(t_camera *camera);
t_viewport		init_viewport(double fov, double distance);
t_alight		*set_alight(double ratio, int color);
void			destroy_alight(t_alight *alight);
t_light			*set_light(t_vector pos, double ratio, int color);
void			destroy_light(t_light *light);
void			set_plane(t_plane **plane, t_vector pos_normal[2], \
		double csr[3]);
void			destroy_plane(t_plane **plane);
void			set_sphere(t_sphere **sphere, t_vector pos, double rcsr[4]);
void			destroy_sphere(t_sphere **sphere);
void			set_cylinder(t_cylinder **cylinder, t_vector pos_axis[2], \
		double dhcsr[5]);
void			destroy_cylinder(t_cylinder **cylinder);

/* OBJECTS LIST */
t_obj			*create_new_obj(void);
t_obj			*get_last_obj(t_obj *obj);
void			init_objs(t_data *data);
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
t_closest_obj	closest_intersection(t_ray ray, t_obj *objs);
t_color			ray_trace(t_data *data, t_ray ray, int depth);

/* AMBIENT LIGHTNING */
t_vector		ambient_lightning_intensity(t_data *data);

/* LIGHT */
t_vector		light_intensity(t_data *data);

/* LIGHT EFFECTS */
t_color			get_obj_color(t_obj *obj);
double			get_obj_reflect_ratio(t_obj *obj);
t_vector		reflection_dir(t_vector normal, t_vector dir);
t_color			reflection_color(t_color color, t_color reflective, \
		double ratio);
t_color			light_effects(t_data *data, t_vector normal, \
		t_closest_obj closest, t_ray ray);

/* RENDERING */
void			rendering(t_minirt *mem);
void			draw_pixels(t_image *img, int x, int y, int color);

#endif