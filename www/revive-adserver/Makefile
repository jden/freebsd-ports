# Created by: Piotr Rybicki <meritus@innervision.pl>
# $FreeBSD$

PORTNAME=	revive-adserver
PORTVERSION=	3.0.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.revive-adserver.org/

MAINTAINER=	meritus@innervision.pl
COMMENT=	Free, opensource ad server in PHP

LICENSE=	GPLv2

NO_BUILD=	yes
SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message
PLIST_SUB+=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	xml pcre zlib mysql pgsql ftp
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
