#ifndef __SYS_PARAM_H__
#define __SYS_PARAM_H__

#include <stdint.h>

#define DEF_SYS_PARAM_ID(id) id

#define SYS_PARAM_ATTR(_name, _type) \
	{.name = _name, .type = _type}

#define SYS_PARAM_TYPE_TO_STRING(type) #type

#define SIZE_OF_PARAM_LIST(list) (sizeof(list) / sizeof(sys_param_data))

enum {
	SYS_PARAM_SUCCEED,
	SYS_PARAM_INDEX_OUT_OF_RANGE
} SYS_PARARM_RETVAL;

enum {
	SYS_PARAM_U8 = 1,
	SYS_PARAM_S8 = 2,
	SYS_PARAM_U16 = 3,
	SYS_PARAM_S16 = 4,
	SYS_PARAM_U32 = 5,	
	SYS_PARAM_S32 = 6,
	SYS_PARAM_FLOAT = 9
} SYS_PARAM_TYPE;

typedef struct {
	char *name;
	int type;

	union {
		uint8_t u8_val; 
		int8_t s8_val;
		uint16_t u16_val;
		int16_t s16_val;
		uint32_t u32_val;
		int32_t s32_val;
		float float_val;
	};
} sys_param_data;

void init_sys_param_list(sys_param_data *list, int _list_size);
int get_sys_param_list_size(void);
int get_sys_param_name(int index, char **name);
int get_sys_param_type(int index, int *type);

int get_sys_param_u8(int index, uint8_t *retval);
int get_sys_param_s8(int index, int8_t *retval);
int get_sys_param_u16(int index, uint16_t *retval);
int get_sys_param_s16(int index, int16_t *retval);
int get_sys_param_u32(int index, uint32_t *retval);
int get_sys_param_s32(int index, int32_t *retval);
int get_sys_param_float(int index, float *retval);

int set_sys_param_u8(int index, uint8_t val);
int set_sys_param_s8(int index, int8_t val);
int set_sys_param_u16(int index, uint16_t val);
int set_sys_param_s16(int index, int16_t val);
int set_sys_param_u32(int index, uint32_t val);
int set_sys_param_s32(int index, int32_t val);
int set_sys_param_float(int index, float val);



#endif
