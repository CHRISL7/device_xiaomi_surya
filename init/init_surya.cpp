/*
 * Copyright (C) 2022 Paranoid Android
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <vector>

#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/sysinfo.h>

using android::base::GetProperty;

void property_override(char const prop[], char const value[], bool add = true) {
    prop_info* pi;

    pi = (prop_info*)__system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else if (add)
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void load_poco_karna() {
    property_override("ro.product.brand", "POCO");
    property_override("ro.product.device", "karna");
    property_override("ro.product.manufacturer", "Xiaomi");
    property_override("ro.product.model", "M2007J20CI");
    property_override("ro.product.name", "karna_in");
    property_override("bluetooth.device.default_name", "POCO X3");
}

void load_poco_thai() {
    property_override("ro.product.brand", "POCO");
    property_override("ro.product.device", "surya");
    property_override("ro.product.manufacturer", "Xiaomi");
    property_override("ro.product.model", "M2007J20CT");
    property_override("ro.product.name", "surya_global");
    property_override("bluetooth.device.default_name", "POCO X3 NFC");
}

void load_poco_surya() {
    property_override("ro.product.brand", "POCO");
    property_override("ro.product.device", "surya");
    property_override("ro.product.manufacturer", "Xiaomi");
    property_override("ro.product.model", "M2007J20CG");
    property_override("ro.product.name", "surya_global");
    property_override("bluetooth.device.default_name", "POCO X3 NFC");
}

void vendor_load_properties() {
    std::string region = GetProperty("ro.boot.hwc", "");
    if (region.find("INDIA") != std::string::npos) {
        load_poco_karna();
    } else if (region.find("THAI") != std::string::npos) {
        load_poco_thai();
    } else {
        load_poco_surya();
    }

    // Set hardware revision
    property_override("ro.boot.hardware.revision", GetProperty("ro.boot.hwversion", "").c_str());
}
