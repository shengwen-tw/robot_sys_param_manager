#include <stdio.h>
#include "sys_param.h"

enum {
	DEF_SYS_PARAM_ID(TEST_U8),
	DEF_SYS_PARAM_ID(TEST_S8),
	DEF_SYS_PARAM_ID(TEST_U16),
	DEF_SYS_PARAM_ID(TEST_S16),
	DEF_SYS_PARAM_ID(TEST_U32),
	DEF_SYS_PARAM_ID(TEST_S32),
	DEF_SYS_PARAM_ID(TEST_FLOAT)
} PARAM_ID;

sys_param_data sys_param_list[] = {
	SYS_PARAM_ATTR("test u8", SYS_PARAM_U8),
	SYS_PARAM_ATTR("test s8", SYS_PARAM_S8),
	SYS_PARAM_ATTR("test u16", SYS_PARAM_U16),
	SYS_PARAM_ATTR("test s16", SYS_PARAM_S16),
	SYS_PARAM_ATTR("test u32", SYS_PARAM_U32),
	SYS_PARAM_ATTR("test s32", SYS_PARAM_S32),
	SYS_PARAM_ATTR("test float", SYS_PARAM_FLOAT)
};

void print_sys_param_list(void)
{
	int i;
	for(i = 0; i < get_sys_param_list_size(); i++) {
		char *name;
		char *type_s;
		int type;
		get_sys_param_name(i, &name);
		get_sys_param_type(i, &type);

		uint8_t u8;
		int8_t s8;
		uint16_t u16;
		int16_t s16;
		uint32_t u32;
		int32_t s32;
		float f;

		switch(type) {
		case SYS_PARAM_U8:
			type_s = SYS_PARAM_TYPE_TO_STRING(SYS_PARAM_U8);
			get_sys_param_u8(i, &u8);
			printf("#%d - name:\"%s\" - type:%s - val:%u\n\r", i, name, type_s, u8);
			break;
		case SYS_PARAM_S8:
			type_s = SYS_PARAM_TYPE_TO_STRING(SYS_PARAM_S8);
			get_sys_param_s8(i, &s8);
			printf("#%d - name:\"%s\" - type:%s - val:%d\n\r", i, name, type_s, s8);
			break;
		case SYS_PARAM_U16:
			type_s = SYS_PARAM_TYPE_TO_STRING(SYS_PARAM_U16);
			get_sys_param_u16(i, &u16);
			printf("#%d - name:\"%s\" - type:%s - val:%u\n\r", i, name, type_s, u16);
			break;
		case SYS_PARAM_S16:
			type_s = SYS_PARAM_TYPE_TO_STRING(SYS_PARAM_S16);
			get_sys_param_s16(i, &s16);
			printf("#%d - name:\"%s\" - type:%s - val:%d\n\r", i, name, type_s, s16);
			break;
		case SYS_PARAM_U32:
			type_s = SYS_PARAM_TYPE_TO_STRING(SYS_PARAM_U32);
			get_sys_param_u32(i, &u32);
			printf("#%d - name:\"%s\" - type:%s - val:%u\n\r", i, name, type_s, u32);
			break;
		case SYS_PARAM_S32:
			type_s = SYS_PARAM_TYPE_TO_STRING(SYS_PARAM_S32);
			get_sys_param_s32(i, &s32);
			printf("#%d - name:\"%s\" - type:%s - val:%d\n\r", i, name, type_s, s32);
			break;
		case SYS_PARAM_FLOAT:
			type_s = SYS_PARAM_TYPE_TO_STRING(SYS_PARAM_FLOAT);
			get_sys_param_float(i, &f);
			printf("#%d - name:\"%s\" - type:%s - val:%f\n\r", i, name, type_s, f);
			break;
		}
	}
}

int main(void)
{
	init_sys_param_list(sys_param_list, SIZE_OF_PARAM_LIST(sys_param_list));

	set_sys_param_u8(TEST_U8, UINT8_MAX);
	set_sys_param_s8(TEST_S8, INT8_MAX);
	set_sys_param_u16(TEST_U16, UINT16_MAX);
	set_sys_param_s16(TEST_S16, INT16_MAX);
	set_sys_param_u32(TEST_U32, UINT32_MAX);
	set_sys_param_s32(TEST_S32, INT32_MAX);
	set_sys_param_float(TEST_FLOAT, 3.141596);

	print_sys_param_list();
	printf("-------------------------------------------------------------\n\r");

	set_sys_param_u8(TEST_U8, 0);
	set_sys_param_s8(TEST_S8, INT8_MIN);
	set_sys_param_u16(TEST_U16, 0);
	set_sys_param_s16(TEST_S16, INT16_MIN);
	set_sys_param_u32(TEST_U32, 0);
	set_sys_param_s32(TEST_S32, INT32_MIN);
	set_sys_param_float(TEST_FLOAT, -3.141596);

	print_sys_param_list();

	return 0;
}
