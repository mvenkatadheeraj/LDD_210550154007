#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
	.exit = cleanup_module,
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(retpoline, "Y");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x4766f4cf, "module_layout" },
	{ 0xc5850223, "printk" },
	{ 0x9f9685ab, "my_add" },
	{ 0xb1ad28ac, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "my_avg");


MODULE_INFO(srcversion, "E9D78FB7C68308B2A7321abf");
