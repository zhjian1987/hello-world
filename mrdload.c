int main(int argc, char * argv[])
{
	int num=0;
	char boardid[PROPERTY_VALUE_MAX];

	handleArg(argc, argv);
	if(g_mrdloader_operation == MRD_LOADER_OPER_EXIT)
		return 0;

	if(g_mrd_scan_enabled) {
		g_mrd_out_list_file = fopen(MRD_FILE_LIST_FULL_NAME, "w");
		if(!g_mrd_out_list_file)
		{
			printf("mrdloader - %s ERROR opening file [%s]\n", __FUNCTION__, MRD_FILE_LIST_FULL_NAME);
			ERROR("%s: ERROR opening file [%s]", __FUNCTION__, MRD_FILE_LIST_FULL_NAME);
			exit(-1);
		}
	}

	MRDMutexInit();
	mrdrc = MRDInit();
	if(mrdrc != MRD_NO_ERROR)
	{
		ERROR("%s: init mrd failed %d", __FUNCTION__, mrdrc);
		if(g_mrd_out_list_file)
			fclose(g_mrd_out_list_file);
		exit(-1);
	}

	system(NVM_FILE_COPY);

	return 0;
}
