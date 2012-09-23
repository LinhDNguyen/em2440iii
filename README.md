Development repository for EM2440-III board.

Update firmware into NAND flash without USB using:
----------------------------------
************New u-boot:
tftp 0x30000000 u-boot.bin; nand erase bios; nand write.jffs2 0x30000000 bios $(filesize)
************New kernel:
tftp 0x30000000 zImage; nand erase kernel; nand write.jffs2 0x30000000 kernel $(filesize)
************New rootfs
tftp 0x30000000 root_qt2.2.0_64MB.bin; nand erase root; nand write.yaffs 0x30000000 root $(filesize)
---------------------------------
