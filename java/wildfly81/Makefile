# Created by: Alexander Yerenkow <yerenkow@gmail.com>
# $FreeBSD$

PORTNAME=	wildfly81
PORTVERSION=	8.1.0
CATEGORIES=	java www
MASTER_SITES=	http://download.jboss.org/wildfly/${WILDFLY_VERSION}/
DISTNAME=	wildfly-${WILDFLY_VERSION}

MAINTAINER=	yerenkow@gmail.com
COMMENT=	Replacement for JBoss Application Server

LICENSE=	GPLv2

USE_RC_SUBR=	wildfly81
USE_JAVA=	yes
JAVA_VERSION=	1.7+
USER=		www
GROUP=		www
VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
PID_FILE=	${VAR_DIR}/run/${PORTNAME}.pid
WILDFLY_VERSION=8.1.0.Final

SUB_LIST=	APP_SHORTNAME=${PORTNAME} \
		LOG_DIR=${LOG_DIR} \
		USER=${USER} \
		GROUP=${GROUP} \
		PID_FILE=${PID_FILE} \
		APP_HOME=${PREFIX}/wildfly-${PORTVERSION}
PLIST_SUB=	APP_HOME=wildfly-${PORTVERSION}

do-build:
	${RM} ${WRKSRC}/bin/*.bat
	${RM} -rf ${WRKSRC}/bin/service
	${RM} -rf ${WRKSRC}/bin/init.d

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION})
	${CHMOD} +x ${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION}/bin/*.sh
	${RMDIR} ${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION}/.installation

.include <bsd.port.mk>
