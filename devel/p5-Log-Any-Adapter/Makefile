# $FreeBSD$

PORTNAME=	Log-Any-Adapter
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to log anywhere

RUN_DEPENDS=	\
	p5-Log-Any>=0.10:${PORTSDIR}/devel/p5-Log-Any \
	p5-Guard>0:${PORTSDIR}/devel/p5-Guard \
	p5-Devel-GlobalDestruction>0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0.12:${PORTSDIR}/devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
