
#include "deviceInfo.h"



deviceInfo::deviceInfo(void)
{
}


deviceInfo::~deviceInfo(void)
{
}


void deviceInfo::PrintLastError(DWORD errCode) 
{
        
        char *err;
        if (!FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                           NULL,
                           errCode,
                           MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // default language
                           (LPTSTR) &err,
                           0,
                           NULL))
		{
			printf("cannot print last error\n");
            return;
		}
        printf("ERROR: %ls\n", err);
        LocalFree(err);
}

int deviceInfo::showInfo()
{
    HDEVINFO hDevInfo;
    SP_DEVINFO_DATA DeviceInfoData;
    DWORD i;
	bool flag;

    // Create a HDEVINFO with all present devices.
    hDevInfo = SetupDiGetClassDevs(NULL,
        0, // Enumerator
        0,
        DIGCF_PRESENT | DIGCF_ALLCLASSES );
       
    if (hDevInfo == INVALID_HANDLE_VALUE)
    {
        // Insert error handling here.
		printf("error\n");
        return 1;
    }
       
    // Enumerate through all devices in Set.
    DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
    for (i=0; SetupDiEnumDeviceInfo(hDevInfo,i, &DeviceInfoData); i++)
    {
		printf("\n\n");
        LPTSTR buffer = NULL;
        DWORD buffersize = 0;
        
        //
        // Call function with null to begin with, 
        // then use the returned buffer size (doubled)
        // to Alloc the buffer. Keep calling until
        // success or an unknown failure.
        //
        //  Double the returned buffersize to correct
        //  for underlying legacy CM functions that 
        //  return an incorrect buffersize value on 
        //  DBCS/MBCS systems.
        // 
		//  this function retrieves a specified Plug and Play device property.
		flag = true;
        while (!SetupDiGetDeviceRegistryProperty(
            hDevInfo,
            &DeviceInfoData,
            SPDRP_DEVTYPE, //SPDRP_PHYSICAL_DEVICE_OBJECT_NAME,  //SPDRP_DEVTYPE,  //SPDRP_DEVICEDESC
            NULL,
            (PBYTE)buffer,
            buffersize,
            &buffersize))
        {
			DWORD errCode = GetLastError();
            if (errCode == ERROR_INSUFFICIENT_BUFFER)
            {
                if (buffer) LocalFree(buffer);
				buffer = new TCHAR[buffersize * 2];
            }
            else
            {
				PrintLastError(errCode);
				flag = false;
                break;
            }
        }
		if(flag)
		{
			printf("%ls \n", buffer);
			//printf("%08x \n", buffer) ;
		}



		flag = true;
        while (!SetupDiGetDeviceRegistryProperty(
            hDevInfo,
            &DeviceInfoData,
            SPDRP_DEVICEDESC,  //SPDRP_DEVTYPE,  //SPDRP_DEVICEDESC
            NULL,
            (PBYTE)buffer,
            buffersize,
            &buffersize))
        {
			DWORD errCode = GetLastError();
            if (errCode == ERROR_INSUFFICIENT_BUFFER)
            {
                if (buffer) LocalFree(buffer);
				buffer = new TCHAR[buffersize * 2];
            }
            else
            {
				PrintLastError(errCode);
				flag = false;
                break;
            }
        }
		if(flag)
		{
			printf("%ls \n", buffer);
			//printf("%08x \n", buffer) ;
		}

           
        if (buffer) LocalFree(buffer);
    }
       
       
    if ( GetLastError()!=NO_ERROR &&
        GetLastError()!=ERROR_NO_MORE_ITEMS )
    {
        // Insert error handling here.
		printf("error\n");
        return 1;
    }
       
    //  Cleanup
    SetupDiDestroyDeviceInfoList(hDevInfo);
       
    return 0;
}