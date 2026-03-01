ENTRY(_start)

SECTIONS 
{
	. = 1M;

	.text : AT(ADDR(.text))
	{
		*(.multiboot)
		*(.text)
	}

	.rodata : AT(ADDR(.rodata))
	{
		*(.rodata)
	}

	.data : AT(ADDR(.data))
	{
		*(.data)
	}

	.bss : AT(ADDR(.bss))
	{
		*(COMMON)
		*(.bss)
	}
}
