# $FreeBSD$

PORTNAME=	libosmo-abis
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	http://git.osmocom.org/libosmo-abis/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Shared code regarding the A-bis interface between BTS and BSC

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libosmocore.so:${PORTSDIR}/devel/libosmocore \
		libortp.so:${PORTSDIR}/net/ortp

USES=		gmake libtool pkgconfig

USE_AUTOTOOLS=	aclocal autoconf automake libtoolize autoheader
AUTOMAKE_ARGS=	--gnu --add-missing --copy
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|pkgconfigdir.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libosmoabis.so.4
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libosmotrau.so.0

.include <bsd.port.mk>
