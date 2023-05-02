#! /vendor/bin/sh
# Copyright (C) 2023 Paranoid Android
# SPDX-License-Identifier: Apache-2.0

    for device in /sys/devices/platform/soc
    do
        #Enable mem_latency governor for L3, LLCC, and DDR scaling
        for memlat in $device/*cpu*-lat/devfreq/*cpu*-lat
        do
            echo "mem_latency" > $memlat/governor
            echo 10 > $memlat/polling_interval
            echo 400 > $memlat/mem_latency/ratio_ceil
         done

         #Gold L3 ratio ceil
         echo 4000 > /sys/class/devfreq/soc:qcom,cpu6-cpu-l3-lat/mem_latency/ratio_ceil

         #Enable cdspl3 governor for L3 cdsp nodes
         for l3cdsp in $device/*cdsp-cdsp-l3-lat/devfreq/*cdsp-cdsp-l3-lat
         do
             echo "cdspl3" > $l3cdsp/governor
         done

        #Enable compute governor for gold latfloor
        for latfloor in $device/*cpu*-ddr-latfloor*/devfreq/*cpu-ddr-latfloor*
        do
            echo "compute" > $latfloor/governor
            echo 10 > $latfloor/polling_interval
        done
    done;