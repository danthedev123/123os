ISO_IMAGE := 123os.iso

.PHONY: clean all run kernel limine

all: kernel $(ISO_IMAGE)

run: $(ISO_IMAGE)
	qemu-system-x86_64 -M q35 -m 2G -cdrom $(ISO_IMAGE)

kernel:
	$(MAKE) -C kernel

limine:
	git clone https://github.com/limine-bootloader/limine.git --branch=v2.0-branch-binary --depth=1
	make -C limine

clean:
	make -C kernel/ clean
	rm -rf $(ISO_IMAGE)

$(ISO_IMAGE): limine kernel/kernel.elf
	rm -rf iso
	mkdir -p iso
	cp kernel/kernel.elf \
		config/limine.cfg limine/limine.sys limine/limine-cd.bin limine/limine-eltorito-efi.bin iso/
	xorriso -as mkisofs -b limine-cd.bin \
		-no-emul-boot -boot-load-size 4 -boot-info-table \
		--efi-boot limine-eltorito-efi.bin \
		-efi-boot-part --efi-boot-image --protective-msdos-label \
		iso -o $(ISO_IMAGE)
	limine/limine-install $(ISO_IMAGE)
	rm -rf iso


