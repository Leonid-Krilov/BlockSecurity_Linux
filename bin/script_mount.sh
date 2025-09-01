#!/bin/bash

DEVICE="$1"
MOUNT_POINT="/mnt/usb_program"

if [ ! -d "$MOUNT_POINT" ]; then
    sudo mkdir -p "$MOUNT_POINT"
    sudo chmod root:adm "$MOUNT_POINT"
fi

sudo mount "$DEVICE" "$MOUNT_POINT"


mount $path /mnt/usb