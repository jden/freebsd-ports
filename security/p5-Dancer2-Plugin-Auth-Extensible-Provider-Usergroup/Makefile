# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Auth-Extensible-Provider-Usergroup
PORTVERSION=	0.22
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Extensible authentication framework for Dancer2 apps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer2>=0.156001:${PORTSDIR}/www/p5-Dancer2 \
		p5-Dancer2-Plugin-Auth-Extensible>=0:${PORTSDIR}/security/p5-Dancer2-Plugin-Auth-Extensible \
		p5-Dancer2-Plugin-Passphrase>=0:${PORTSDIR}/security/p5-Dancer2-Plugin-Passphrase
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
