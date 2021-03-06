# Created by: Jimmy Kelley <ljboiler@gmail.com>
# $FreeBSD$

PORTNAME=	eclipse
PORTVERSION=	4.3.2
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	https://googledrive.com/host/0B2kYpXHnC5LpSk01bU1ud0N5bXc/
DISTFILES=	eclipse.platform.releng.aggregator-${PORTVERSION}.xz \
		${PORTNAME}-maven-repo-${PORTVERSION}.xz
DIST_SUBDIR=	eclipse

MAINTAINER=	ljboiler@gmail.com
COMMENT=	Eclipse Kepler SR-2

LICENSE=	EPL

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven31/bin/mvn:${PORTSDIR}/devel/maven31
LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

ONLY_FOR_ARCHS=	i386 amd64
CONFLICTS_INSTALL=	eclipse

USES=		gmake pkgconfig tar:xz
USE_GL=		glu
USE_GNOME=	gconf2 gtk20 gnomevfs2 libgnome libgnomeui
USE_JAVA=	yes
JAVA_OS=	native
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes

OPTIONS_SINGLE=			INSTALLPKG
OPTIONS_SINGLE_INSTALLPKG=	FULL_SDK PLATFORM_SDK PLATFORM
FULL_SDK_DESC=		Full SDK (JDT, PDE, source, API docs)
PLATFORM_SDK_DESC=	Platform with source, API Docs (no Java tools)
PLATFORM_DESC=		Platform only (no Java tools, no source or docs)

OPTIONS_DEFAULT=	FULL_SDK

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
PATCH_DEPENDS+=	gpatch:${PORTSDIR}/devel/patch
PATCH=		gpatch
.endif
PATCH_STRIP=	-p1

WRKSRC=${WRKDIR}/eclipse.platform.releng.aggregator-${PORTVERSION}
GITCLONE=${DISTDIR}/eclipse/eclipse-gitclone/eclipse.platform.releng.aggregator

MVN_LOCAL_REPO=	-Dmaven.repo.local=${WRKDIR}/eclipse-maven-repo-${PORTVERSION}/repository
MVN_TEST_FLAG=	-Dmaven.test.skip=true
MVN_SETTINGS+=	--offline
ECLIPSE_WS=	gtk
ECLIPSE_ARCH=	x86${ARCH:C/^i.86//:C/^amd/_/}
E_SHORTARCH=	${ARCH:C/^i.86//:C/^amd//}
ECLIPSE_BUILDID=M20140224-0627
SCRIPTS_ENV+=	ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		E_SHORTARCH=${E_SHORTARCH}
PORTDESTDIR=	${PREFIX}/lib/eclipse

#  Someday it would be nice to see about moving the product selection into the patch phase (and only build the
#  product the user wants), but that may prove to be difficult if not impossible with the way the eclipse tycho
#  builder is a "all-or-nothing" thing right now.
.if ${PORT_OPTIONS:MFULL_SDK}
PRODUCT_TARFILE=	\
	${WRKSRC}/eclipse.platform.releng.tychoeclipsebuilder/sdk/target/products/org.eclipse.sdk.ide-freebsd.${ECLIPSE_WS}.${ECLIPSE_ARCH}.tar.gz
.endif
.if ${PORT_OPTIONS:MPLATFORM_SDK}
PRODUCT_TARFILE=	\
	${WRKSRC}/eclipse.platform.releng.tychoeclipsebuilder/platform.sdk/target/products/org.eclipse.platform.sdk-freebsd.${ECLIPSE_WS}.${ECLIPSE_ARCH}.tar.gz
.endif
.if ${PORT_OPTIONS:MPLATFORM}
PRODUCT_TARFILE=	\
	${WRKSRC}/eclipse.platform.releng.tychoeclipsebuilder/platform/target/products/org.eclipse.platform.ide-freebsd.${ECLIPSE_WS}.${ECLIPSE_ARCH}.tar.gz
.endif

post-patch:
	@(for f in `${GREP} -hE '(\-\-\-|%%ECLIPSE_ARCH%%)' ${FILESDIR}/patch-* | ${GREP} -B1 'ECLIPSE_ARCH' | ${GREP} '^\-\-\-' | ${SED} -e 's/^\-\-\- .\///'` ; \
	do \
	  ${ECHO_MSG} "Updating ECLIPSE_ARCH in file $$f"; \
	  ${REINPLACE_CMD} -e "s|%%ECLIPSE_ARCH%%|${ECLIPSE_ARCH}|g" ${WRKSRC}/$$f; \
	done)

do-build:
	@(cd ${WRKSRC}; ${SETENV} JAVA_HOME=${JAVA_HOME} M2_HOME=${LOCALBASE}/share/java/maven31 ${MVN_OPTS} \
		mvn ${MVN_SETTINGS} ${MVN_TEST_FLAG} ${MVN_LOCAL_REPO} clean verify -Dnative=${ECLIPSE_WS}.freebsd.${ECLIPSE_ARCH} \
		-DbuildId=${ECLIPSE_BUILDID} -Pupdate-branding-plugins)

do-install:
	@${RM} -rf ${STAGEDIR}${PORTDESTDIR}
	@( cd ${STAGEDIR}${PREFIX}/lib; ${TAR} xfz ${PRODUCT_TARFILE} )
	@${FIND} ${STAGEDIR}${PREFIX}/lib -type f -name \*.orig -delete
	@${SED} \
	  -e "s+%%BROWSER%%+${GECKO:S/19//}+g" \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%JAVA_HOME%%+${JAVA_HOME}+g" \
	  -e "s+%%JAVA_OS%%+${JAVA_OS}+g" \
	  -e "s+%%JAVA_VERSION%%+${JAVA_VERSION}+g" \
	  -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
	  ${FILESDIR}/eclipse.in > ${BUILD_WRKSRC}/eclipse.tmp
.if defined(JAVA_VENDOR)
	@${REINPLACE_CMD} -e "s+%%JAVA_VENDOR_SPECIFICATION%%+JAVA_VENDOR=\"${JAVA_VENDOR}\"+g" \
	  ${BUILD_WRKSRC}/eclipse.tmp
.else
	@${REINPLACE_CMD} -e "s+%%JAVA_VENDOR_SPECIFICATION%%++g" \
	  ${BUILD_WRKSRC}/eclipse.tmp
.endif
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/eclipse.tmp ${STAGEDIR}${PREFIX}/bin/eclipse
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s lib/eclipse -not -type d) >> ${TMPPLIST}
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s bin/eclipse -not -type d) >> ${TMPPLIST}
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s -d lib/eclipse -type d -empty) | ${SED} -ne "s,^,@dir ,p" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo '-Dorg.eclipse.equinox.p2.reconciler.dropins.directory=%D/share/eclipse/dropins' >> %D/lib/eclipse/eclipse.ini" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${SED} -i '' '/^-Dorg.eclipse.equinox.p2.reconciler.dropins.directory=/d' %D/lib/eclipse/eclipse.ini" >> ${TMPPLIST}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/eclipse/dropins
	@${ECHO_CMD} "@dir share/eclipse/dropins" >> ${TMPPLIST}

distclean:
	${RM} -rf ${DISTDIR}/eclipse

.include <bsd.port.mk>
