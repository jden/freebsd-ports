# Created by: gelf
# $FreeBSD$

PORTNAME=	fte
PORTVERSION=	20110708
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION:S/./b/}-src.zip \
		${PORTNAME}-${PORTVERSION:S/./b/}-common.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-featured text editor for X11

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/fte

USES=		perl5 zip
USE_PERL5=	build
USE_XORG=	x11 xpm

CFLAGS+=	-DHAVE_STRLCAT -DHAVE_STRLCPY

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX=|PREFIX?=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|\([[:space:]]\)\($$BINDIR\)|\1$$DESTDIR\2|g ; \
		 s|\([[:space:]]\)\($$LIBDIR\)|\1$$DESTDIR\2|g ; \
		 s|\([[:space:]]\)\($$CONFIGDIR\)|\1$$DESTDIR\2|g ; \
		 s|\([[:space:]]\)\($$LOCALCONFIGDIR\)|\1$$DESTDIR\2|g ; \
		 /fterc/s|^|#|' ${WRKSRC}/install

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.for i in cfte xfte
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
