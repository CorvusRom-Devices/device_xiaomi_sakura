/*
   Copyright (c) 2016, The CyanogenMod Project
   Copyright (c) 2019, The LineageOS Project

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "property_service.h"
#include "vendor_init.h"

void property_override(char const prop[], char const value[])
{
	prop_info *pi;
	pi = (prop_info *)__system_property_find(prop);
	if (pi)
		__system_property_update(pi, value, strlen(value));
	else
		__system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_multifp(char const buildfp[], char const systemfp[],
	char const bootimagefp[], char const vendorfp[], char const value[])
{
    property_override(buildfp, value);
    property_override(systemfp, value);
    property_override(vendorfp, value);
    property_override(bootimagefp, value);
}

void load_dalvik_properties()
{
	struct sysinfo sys;

	sysinfo(&sys);

	if (sys.totalram > 3072ull * 1024 * 1024)
	{
		// from - phone-xxhdpi-4096-dalvik-heap.mk
		property_override("dalvik.vm.heapstartsize", "8m");
		property_override("dalvik.vm.heaptargetutilization", "0.6");
		property_override("dalvik.vm.heapgrowthlimit", "256m");
		property_override("dalvik.vm.heapsize", "512m");
		property_override("dalvik.vm.heapmaxfree", "16m");
		property_override("dalvik.vm.heapminfree", "8m");
	}
	else
	{
                // from - phone-xhdpi-2048-dalvik-heap.mk
		property_override("dalvik.vm.heapstartsize", "8m");
		property_override("dalvik.vm.heaptargetutilization", "0.7");
		property_override("dalvik.vm.heapgrowthlimit", "192m");
		property_override("dalvik.vm.heapsize", "512m");
		property_override("dalvik.vm.heapmaxfree", "8m");
		property_override("dalvik.vm.heapminfree", "512k");
	}
}

void vendor_load_properties()
{
	load_dalvik_properties();

	// fingerprint
	property_override("ro.build.description", "redfin-user 11 RQ3A.210705.001 7380771 release-keys");
	property_override_multifp("ro.build.fingerprint", "ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.bootimage.build.fingerprint", "google/redfin/redfin:11/RQ3A.210705.001/7380771:user/release-keys");

	// Magisk Hide
	property_override("ro.boot.verifiedbootstate", "green");
	property_override("ro.boot.vbmeta.device_state", "locked");
	property_override("ro.boot.veritymode", "enforcing");
	property_override("ro.build.type", "user");
	property_override("ro.build.tags", "release-keys");
}
