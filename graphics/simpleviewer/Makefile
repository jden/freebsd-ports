# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simpleviewer
PORTVERSION=	1.7.1553.8560
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OpenGL%20edition
DISTNAME=	sviewgl-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and simple OpenGL image viewer with transparency support

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib

USES=		tar:bzip2
USE_EFL=	imlib2
USE_GL=		glut
WRKSRC=		${WRKDIR}/sviewgl-src
MAKE_ARGS=	CC="${CXX}"

PLIST_FILES=	bin/sviewgl

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,${CFLAGS}, ; s,/usr/include,${LOCALBASE}/include,g ; \
		s,=-s,=-L${LOCALBASE}/lib,' ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sviewgl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
