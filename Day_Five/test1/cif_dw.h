#ifndef __CIF_DW_H__
#define __CIF_DW_H__

// 写配置文件
int WriteConfigFile(const char *_in_file_name, const char *_in_key, const char *_in_value);

// 读配置文件
int ReadConfigFile (const char *_in_file_name, const char *_in_key, char *_inout_value);

#endif
