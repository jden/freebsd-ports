# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dgen-sdl
PORTVERSION=	1.33
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/dgen/dgen/${PORTVERSION}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Wonderful Sega Genesis/MegaDrive emulator

USE_SDL=	sdl
USE_GL=		yes
USES=		fmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/dgen \
		bin/dgen_tobin \
		man/man1/dgen.1.gz \
		man/man1/dgen_tobin.1.gz \
		man/man5/dgenrc.5.gz

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.else
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.post.mk>
