#! /usr/bin/bash
# mkdir new_kernel1
# cd new_kernel1
# wget https://git.kernel.org/torvalds/t/linux-5.19.8.tar.gz
# tar xvzf linux-5.19.8.tar.gz
# cd linux-5.19.8
# make mrproper
# cp ~/config_file_downloaded .config
# make olddefconfig
# make
# make modules
# make modules_install
# make bzImage
# cp -v arch/x86/boot/bzImage /boot/vmlinuz-linuxscrip1
# mkinitcpio -k 5.19.8 -g /boot/initramfs-linuxscrip1.img
# cp System.map /boot/System.map-linuxscrip1
# ln -sf /boot/System.map-linuxscrip1 /boot/System.map
# sudo grub-mkconfig -o /boot/grub/grub.cfg
#! /usr/bin/bash
#mkdir new_kernel3
#cd new_kernel3
#wget https://git.kernel.org/torvalds/t/linux-5.19.8.tar.gz
#tar xvzf linux-5.19.8.tar.gz
cd /home/surislaptop/linux-scrip1/linux-5.19.8
#make mrproper
#cp ~/config_file_downloaded .config
#make olddefconfig
make -j$(nproc)
#make modules

#make bzImage
# cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-linux-scrip11
# make modules_install
# sed s/linux/linux-scrip11/g </etc/mkinitcpio.d/linux.preset >/etc/mkinitcpio.d/linux-scrip11.preset
# mkinitcpio -p linux-scrip11

# Update bootloader entries with new kernels.
#grub-mkconfig -o /boot/grub/grub.cfg
#mkinitcpio -k 5.19.8 -g /boot/initramfs-linuxscrip3.img
#cp System.map /boot/System.map-linuxscrip3
#ln -sf /boot/System.map-linuxscrip3 /boot/System.map
#sudo grub-mkconfig -o /boot/grub/grub.cfg
