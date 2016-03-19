SRCDIR   = src
OBJDIR   = build
OUTDIR   = bin
OUTFILE  = firmware
CC       = /opt/microchip/xc8/v1.35/bin/xc8
CCFLAGS  = --asmlist --chip=16F54 --opt=asm,space --ext=cci

SRCFILES = $(wildcard ${SRCDIR}/*.c)
OBJFILES = $(patsubst ${SRCDIR}/%.c, ${OBJDIR}/%.p1, ${SRCFILES})

all: ${OBJFILES} ${OUTDIR}
	${CC} ${CCFLAGS} -O${OUTFILE} --objdir=${OBJDIR} --outdir=${OUTDIR} $<
${OBJDIR}/%.p1: ${SRCDIR}/%.c ${OBJDIR}
	${CC} ${CCFLAGS} -C --objdir=${OBJDIR} --outdir=${OBJDIR} $<
clean:
	-rm -rf ${OUTDIR}
	-rm -rf ${OBJDIR}
${OBJDIR}:
	mkdir ${OBJDIR}
${OUTDIR}:
	mkdir ${OUTDIR}
