# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	libsigc++20
PORTVERSION=	2.2.4.2
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Callback Framework for C++(Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-libsigc++20-[0-9]*

USE_LINUX=	c6
USE_LINUX_RPM=	yes

RPMVERSION=	1.el6
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libsigc-2.0.so.0.0.0 usr/lib/libsigc-2.0.so.0
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
