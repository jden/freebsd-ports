# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	PerlIO-via-symlink
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Symbolic link PerlIO layers

BUILD_DEPENDS=	p5-Module-Install>0:${PORTSDIR}/devel/p5-Module-Install

USES=		perl5
USE_PERL5=	configure

post-patch:
	# Really old M::I code
	${RM} -rf ${WRKSRC}/inc

.include <bsd.port.mk>
