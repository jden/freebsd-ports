# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	App-Cmd
PORTVERSION=	0.323
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	App::Cmd - Write command line apps with less suffering

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Capture-Tiny>=0.13:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load \
		p5-Getopt-Long-Descriptive>=0.084:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-IO-TieCombine>=0:${PORTSDIR}/devel/p5-IO-TieCombine \
		p5-String-RewritePrefix>=0:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-Getopt-Long>=2.39:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS+=	p5-Getopt-Long>=2.39:${PORTSDIR}/devel/p5-Getopt-Long
.endif

.include <bsd.port.post.mk>
