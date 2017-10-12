package com.tangosol.examples.rest.application;

import org.glassfish.jersey.server.ResourceConfig;

/**
 * The Coherence REST Demo Web Application {@link ResourceConfig}.
 *
 * @author Brian Oliver
 * @since 12.2.1
 */
public class ApplicationResourceConfig extends ResourceConfig
    {
    /**
     * Constructs the {@link ApplicationResourceConfig}.
     */
    public ApplicationResourceConfig()
        {
        register(StaticResource.class);
        }
    }

